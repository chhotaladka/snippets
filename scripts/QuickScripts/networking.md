Networking related terminal commands and features.
==================================================

1. Add a _bridge_ interface `br0`
  ```bash
  brctl addbr br0
  ```
  
  or
  
  ```bash
  ip link add br0 type bridge
  ```
  
2. Add a _Virtual ethernet_ interface pair `veth0` and `veth1`
  ```bash
  ip link add type veth
  ```
  
  or
  
  ```bash
  ip link add dev veth0 type veth peer name veth1
  ```
  
3. Add interface `veth0` to bridge `br0`
  ```bash
  brctl addif br0 veth0 
  ```
  
  or
  
  ```bash
  ip link set veth0 master br0
  ```
  
4. Set MAC Address of an interface (say `veth0`)
  ```bash
  ifconfig veth0 hw ether 00:12:33:00:dd:56
  ```

5. Remove IP Address `10.10.1.3/24` from interface `eth1`
  ```bash
  ip addr del 10.10.1.3/24 dev eth1
  ```

6. Remove all IP Addresses from interface `eth1`
  ```bash
  ip addr flush dev eth1
  ```

7. Ping from a particular interface `eth1`
  ```bash
  ping -I eth1 10.3.4.4
  ``` 
  
8. Add a Tap interface
  ```bash
  ip tuntap add tapm mode tap
  ```
  
9. Bring Up/Down an interface using iproute2 suite
  ```bash
  ip link set dev eth1 up
  ```

10. Create a namespace
  ```bash
  ip netns add vrf1
  ```

11. Assign interface to a VRF
  ```bash
  ip link set eth0 netns vrf1
  ```


12. Create a VLAN interface on an interface
  ```
  ip link add link eth0 name phy-1-1-1 type vlan id 1
  ```

## MPLS related
Taken from [stackoverflow post](https://stackoverflow.com/questions/31926342/iproute2-commands-for-mpls-configuration)

Trying to figure out how one can use iproute2 to manage static label-switched MPLS routes in Linux kernel 4.1.

- Documentation/networking/mpls-sysctl.txt

  ```
  /proc/sys/net/mpls/platform_labels 
  /proc/sys/net/mpls/conf//input
  ```

- Load mpls module
  ```
  sudo modprobe mpls_router 
  ```

- Find sysctl support

  ```
  sysctl -a --pattern mpls 
  net.mpls.conf.eth0.input = 0 
  net.mpls.conf.eth1.input = 0 
  net.mpls.conf.lo.input = 0 
  net.mpls.platform_labels = 0 
  ```
- Enable mpls support

  ```
  sudo sysctl -w net.mpls.conf.eth0.input=1 
  sudo sysctl -w net.mpls.conf.eth1.input=1 
  sudo sysctl -w net.mpls.platform_labels=1000 
  ```
  
- Routing 10.10.10.10/32 to 192.168.1.2 with label 100:

  ```
  ip route add 10.10.10.10/32 encap mpls 100 via inet 192.168.1.2
  ```
- Label swapping 100 for 200 and sent to 192.168.2.2:

  ```
  ip -f mpls route add 100 as 200 via inet 192.168.2.2
  ```
- Decapsulating label 300 and delivering locally:

  ```
  ip -f mpls route add 300 dev lo
  ```
  
- To show MPLS routes you can do:

  ```
  ip -f mpls route show
  ```
