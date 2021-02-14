package aerocomsystem2;

module AirCraft
{
    submodules:
        pktGenerator : PktGenerator;
        iface : NetworkInterface;
    connections:
        pktGenerator.out --> iface.in;
}
