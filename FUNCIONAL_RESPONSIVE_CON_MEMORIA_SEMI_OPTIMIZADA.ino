
#include <SPI.h>
#include <Ethernet.h>


//Servo microservo; 
//int pos = 0; 
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };   //Direccion Fisica MAC
byte ip[] = { 192, 168, 1, 50 };                       // IP Local que usted debe configurar 
byte gateway[] = { 192, 168, 1, 254 };                   // Puerta de enlace
byte subnet[] = { 255, 255, 255, 0 };                  //Mascara de Sub Red
EthernetServer server(80);                             //Se usa el puerto 80 del servidor     
String readString;

void setup() {

  Serial.begin(9600);  // Inicializa el puerto serial 
   while (!Serial) {   // Espera a que el puerto serial sea conectado, Solo necesario para el Leonardo
    ; 
  }
  pinMode(2,OUTPUT);        // Se configura como salidas los puertos del 2 al 6
  pinMode(3,OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5,OUTPUT);
//  pinMode(6,OUTPUT);
//  microservo.attach(7);  // Se configura como Servo el Puerto 7
 
  Ethernet.begin(mac, ip, gateway, subnet); // Inicializa la conexion Ethernet y el servidor
  server.begin();
  Serial.print("El Servidor es: ");
  Serial.println(Ethernet.localIP());    // Imprime la direccion IP Local
}



void loop() {
  // Crea una conexion Cliente
  EthernetClient client = server.available();
  if (client) {
    while (client.connected()) {   
      if (client.available()) {
        char c = client.read();
     
        //Lee caracter por caracter HTTP
        if (readString.length() < 100) {
          //Almacena los caracteres a un String
          readString += c;
          
         }

         // si el requerimiento HTTP fue finalizado
         if (c == '\n') {          
           Serial.println(readString); //Imprime en el monitor serial
     
          
          client.println("<html><head>");  
          //client.println("<meta http-equiv='content-type' content='text/html; charset=utf-8' />");

         
         // client.println("<script src='http://domoticaobertonica.000webhostapp.com/js/jquery.min.js'></script>");
          client.println("<script src='http://domoticaobertonica.000webhostapp.com/js/config.js'></script>");  
          client.println("<script src='http://domoticaobertonica.000webhostapp.com/js/skel.min.js'></script>"); // ESTE ES EL HOMBRE QUE ACTIVA EL TAMAÑO CORRECTO MOVIL
          client.println("<script src='https://use.fontawesome.com/d6622199c5.js'></script>");
         client.println("<link rel='stylesheet' href='http://domoticaobertonica.000webhostapp.com/CSS/skel-noscript.css' />");  
          client.println("<link rel='stylesheet'  href='http://domoticaobertonica.000webhostapp.com/CSS/style.css' />");
          client.println("<link rel='stylesheet' href='http://domoticaobertonica.000webhostapp.com/CSS/style-mobile.css' /></head><body><br/>");  
          client.println("<div class=\"container\"><div class=\"row\">");

          //cuadro 1
          client.println("<div class=\"4u\"><section class=\"box box-style1\"><span class=\"icon featured-icon icon-lightbulb\"></span><h3>Luz del cuarto Principal</h3>");  
          client.println("<p><br><a href=\"/?B1\"\" class=\"button button-small\">Encender rojo</a></span>");
          client.println("<p><br><a href=\"/?B2\"\" class=\"button button-small\">Apagar Rojo</a></span>"); 
          client.println("<p><br><a href=\"/?B3\"\" class=\"button button-small\">Encender Azul</a></span>"); 
          client.println("<p><br><a href=\"/?B4\"\" class=\"button button-small\">Apagar Azul</a></span>"); 
          client.println("<p><br><a href=\"/?B5\"\" class=\"button button-small\">Navidad</a></span>");
          client.println(" <p><a href=\"/?B6\"\" class=\"button button-small\">Apagar Todos</a></span></p></section></div>");         
          client.println("</div></div></article></div></body></html>");
   
           delay(1);
           //detiene el cliente servidor
           client.stop();
           
           //control del arduino si un boton es presionado
                   
           if (readString.indexOf("?B1") >0){
               digitalWrite(2, HIGH);
           }
           if (readString.indexOf("?B2") >0){
               digitalWrite(2, LOW);
           }
           
           if (readString.indexOf("?B3") >0){
               digitalWrite(3, HIGH);
           }
           if (readString.indexOf("?B4") >0){
               digitalWrite(3, LOW);
           }
           
           
          

            if (readString.indexOf("?B5") >0){

               digitalWrite(2, HIGH);           
                 delay(1000); 
                 digitalWrite(3, HIGH);           
                 delay(1000); 
                 digitalWrite(4, HIGH);           
                 delay(1000); 
                 digitalWrite(5, HIGH);           
                 
           
           }       
        
           if (readString.indexOf("?B6") >0){
               digitalWrite(2, LOW);
               digitalWrite(3, LOW);
               digitalWrite(4, LOW);
               digitalWrite(5, LOW);
           }


           
           
          
          
            // Limpia el String(Cadena de Caracteres para una nueva lectura
            readString="";  
           
         }
       }
    }
}
}
