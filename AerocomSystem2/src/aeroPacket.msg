//definizione del pacchetto AeroMessage

message AeroPacket {
    int sender; //id dell'AC xhe ha generato il pacchetto
    simtime_t generationTime; //istante in cui il messaggio e' stato creato
    simtime_t queueLeavingTime; // istante in cui il messaggio e' entrato in coda
    simtime_t ifaceLeavingTime; // istante in cui il messaggio e' ha lasciato l'interfaccia
    simtime_t controlTowerArrivalTime; 	//istante in cui il messaggio e' stato creato.
    									//uguale a ifaceLeavingTime, poiche' non ci sono ritardi di trasmissione
    int packetLength; //in byte 
}
