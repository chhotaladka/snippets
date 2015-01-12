'''
This script takes a config file (see sample config file) as input,
parses it and creates a xml file corresponding to the original file

The pattern to capture configuration is defined in `config` variable, and may be modified
as per requirements  
'''
import fileinput
import xml.etree.ElementTree as ET
import re
import sys

class InputError(Exception):
    def __init__(self, msg):
        self.msg = msg
    def __str__(self):
        return str(self.msg)

class NonUnique(Exception):
    def __init__(self, tag='ID'):
        self.msg = 'Non Unique '+ tag+ '.'
    def __str__(self, *args, **kwargs):
        return str(self.msg)

comments = []
#The following regular expressions qualify as comments
COMMENTS = [r'#.*?$', r'/\*+.*\*/$', r'^\s?$']
for comment_pattern in COMMENTS:
    comments.append(re.compile(comment_pattern))

config = re.compile(r'(?P<code>0[Xx][0-9A-Fa-f]{8})\s+(?P<name>[A-Za-z_0-9]+)\s+(?P<location>\d+)')

def add_to_tree(line, root):
    line.create_config_node(root)
    root.add_node(line.node)

def indent(elem, level=0):
    i = "\n" + level*"  "
    if len(elem):
        if not elem.text or not elem.text.strip():
            elem.text = i + "  "
        if not elem.tail or not elem.tail.strip():
            elem.tail = i
        for elem in elem:
            indent(elem, level+1)
        if not elem.tail or not elem.tail.strip():
            elem.tail = i
    else:
        if level and (not elem.tail or not elem.tail.strip()):
            elem.tail = i

class ConfigLine:    
    def __init__(self, line):
        if line is None:
            raise InputError('No line has been entered')
        self.line = line
        self.is_comment = False
        self.regex = {}
        self.node = ET.Element('product')
    
    def create_config_node(self, tree):
        #Find out the PCT Code Name and Location of Product
        self.regex = config.match(self.line)
        if self.regex:
            #print '\nCode: '+ self.regex.group('code')+'\nName: '+self.regex.group('name')+'\nLocation: '+self.regex.group('location')
            ET.SubElement(self.node, 'code').text = self.regex.group('code')
            ET.SubElement(self.node, 'name').text = self.regex.group('name')
            ET.SubElement(self.node, 'location').text = self.regex.group('location')

class ConfigTree:
    def __init__(self):
        self.root = ET.Element('config')
        self.tree = ET.ElementTree(self.root)

    def add_node(self, node):
        self.root.append(node)
    
try:
    if len(sys.argv)< 0:
        raise InputError('Filename missing')
        exit()
    #open the file
    print 'Trying to convert {file}'.format(file=sys.argv[1])
    fd = fileinput.input(sys.argv[1])
    #Create an ETree Object
    root = ConfigTree()
    #read it line by line until the end of file
    for line in fd:
        #find out if line is config line or comment
        try:
            current_line = ConfigLine(line)
            for comment_pattern in comments:
                if comment_pattern.match(current_line.line):
                    current_line.is_comment = True
                    break
                else: 
                    pass
                    
            if current_line.is_comment:
                pass
            else:
                add_to_tree(current_line, root)
        except InputError:
            exit()       
    indent(root.root)
    print ET.tostring(root.root)
    name = re.split(r'\.', sys.argv[1])[0]
    root.tree.write(name+'.xml')
    
except IOError:
    print 'No such file exists'