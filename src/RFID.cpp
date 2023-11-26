
#include <LibRobus.h> // Essentielle pour utiliser RobUS

char crecu, j, incoming=0;
char id_tag[20];

void RFIDInit()
{
  BoardInit();
  Serial2.begin(9600);
  Serial.println("Test du ID-12 sur UART2 (RX2/Digital 17)");
}

bool RFIDloop()
{
  while(1)
  {
    if( Serial2.available() )
    {
      crecu=Serial2.read();     // lit le ID-12
      switch( crecu )
      {
        case 0x02:
          // START OF TRANSMIT
          AX_BuzzerON();
          j=0;
          incoming=1;
          break;
        case 0x03:
          // END OF TRANSMIT
          AX_BuzzerOFF();
          incoming=0;
          // Affiche le code recu sans valider le checksum
          for( j=0 ; j<10 ; j++ )
            Serial.print(id_tag[j]);
          return 1;
          Serial.println("");
          break;
        default:
          if( incoming )
            id_tag[j++] = crecu;
          break;
      }
    }
  }
}

/* fin du fichier */