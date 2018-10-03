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
