
package aerocomsystem2;

simple DataLink
{
    // tutti i parametri vengono settati nei file .ini
    parameters:
        double minCapacity = default(0);
        double maxCapacity = default(125000000); // in Bps
        string distribution = default("exp");
        double distrMean = default(0.003); 
        double distrVar = default(0);	//utile solo nel caso lognormale
    gates:
        input dataLinkIn @directIn; //puo' ricevere pacchetti da tutti gli AC
        output dataLinkOut;
}
