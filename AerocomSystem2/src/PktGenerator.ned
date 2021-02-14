package aerocomsystem2;

simple PktGenerator
{
    parameters:
        int packetLength = default(1400); //in Byte, defautl in 4G 
        double mean;
    gates:
        output out;
}
