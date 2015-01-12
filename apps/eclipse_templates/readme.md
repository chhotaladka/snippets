README
------

The following code and commenting templates for eclipse are available for download and reuse.

1. Function definition: __(c_fun)__

    ```C
	/**PROC+**********************************************************************/
	/* Name:      ${fun_name} */
	/*                                                                           */
	/* Purpose:   ${cursor}		*/
	/*                                                                           */
	/*			  ${ret_val}													 */
	/* Returns:   RC_OK            	-  The method was successful, and  			 */
	/*                                     identified no problems.               */
	/*                                                                           */
	/*            RC_ERR  			-  	The method failed.  					 */
	/*                                                                           */
	/* Params:    IN/OUT param1      - 	Parameter that can be used both as input */
	/*									and output.								 */
	/*                                                                           */
	/*            IN     param2      - 	Input parameter				           	 */
	/*                                                                           */
	/*            OUT    param3       - Output only parameter (usually a pointer)*/
	/*                                                                           */
	/*                                                                           */
	/* Operation: TODO															 */
	/*                                                                           */
	/**PROC-**********************************************************************/
	${ret_val} ${fun_name}()
	{
		/***************************************************************************/
		/*	Local Variables														   */
		/***************************************************************************/
		/***************************************************************************/
		/*	Sanity Checks														   */
		/***************************************************************************/
	
		/***************************************************************************/
		/*	Main Routine														   */
		/***************************************************************************/
		
		/***************************************************************************/
		/*	Exit Checks															   */
		/***************************************************************************/
			
	} /* ${fun_name} */
	```
2. Line comment: __(c_lin)__
	```C
	/***************************************************************************/
	/* ${cursor}	    */
	/***************************************************************************/
	```

3. Structure declaration: __(c_struct)__
	```C
	/**STRUCT+********************************************************************/
	/* Structure: ${typedef_name}												 */
	/*                                                                           */
	/* Name:      ${struct_name}												 */
	/*                                                                           */
	/* Textname:  ${text_name}	*/
	/*                                                                           */
	/* Owner:     ${owner}                                            */
	/*                                                                           */
	/* Description: ${descr}        */
	/*                                                                           */
	/*****************************************************************************/
	typedef struct ${struct_name} {
		${cursor}
	} ${typedef_name};
	
	/**STRUCT-********************************************************************/
	```


### How to import?

goto `Window>Preferences>C/C++>Editor>templates>import` 

and chose the file downloaded.

### Usage:

When you want to use a particular template in your code (given that you are in a C/C++ perspective), 
just type the usage symbol (e.g.: `c_lin`) and press `Ctrl+Spacebar`. In case more than one options are 
available, Eclipse will show them all. Choose accordingly.
