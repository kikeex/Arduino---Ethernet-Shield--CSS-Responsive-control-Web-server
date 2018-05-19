# Arduino---Ethernet-Shield--CSS-Responsive-control-Web-server
¿Todos queremos automatizar un proceso cierto? Todos buscamos la forma de mejorar nuestra calidad de vida empleando la tecnología. Pero en muchas ocasiones los precios van más allá de nuestro presupuesto, y allí es donde entra nuestro amigo Arduino. 

Somos inteligentes, sabemos programar y somos frikis .Partiendo de estas premisas y debido a que llegaste a mi sitio web, es muy probable que tengas un Arduino y que estés buscando la forma de sacarle provecho. Todos hicimos búsquedas similares, en mi caso el primer proyecto que me interesó fue el de un servidor web de domotica para controlar diferentes puntos del hogar. El único problema fue que cada proyecto ejemplo que encontraba era más feo que el anterior. 

Debido a la memoria reducida de nuestros Arduinos, estos servidores generalmente emplean únicamente HTML plano, dando un acabado muy Old School a los servidores; por ello me pregunté: ¿Por qué no hago entonces un servidor web estéticamente agradable y funcional? Y Aquí es donde empieza nuestro post actual. 


# ¿Qué necesitamos para el prototipo? 

Arduino UNO
Ethernet shield
Un protoboard
Cable para el proto
4 LEDs y resistencias de 220Ohm
Arduino IDE
Router 

# Explicación del proyecto

El Arduino será configurado con una dirección IP dentro de nuestra LAN, por ello será un host más. Adicionalmente, será programado para cargar vía HTTP una interfaz web atractiva al usuario mediante la cual podrá controlar diferentes funciones de su hogar (Luces, aire etc) en nuestro caso, ya que es un prototipo trabajaremos con encendido de LED. La interfaz será accesible desde cualquier tipo de dispositivo (responsive) y podrán ejecutarse ordenes dentro y fuera de la red local. 

¿Qué tal suena esto? Que vayas saliendo del trabajo o de la universidad, saques tu teléfono y mientras vas en camino enciendes tu aire ¿Atractivo no?

Recuerda que la configuración de red debe ser modificada en el código, empleando el segmento de red adecuado a tu LAN. Y también es importante que noten, que estoy haciendo referencias a ficheros CDN de JQUERY y varias hojas de estilo. Todas están hospedadas en servidores personales, por ello es probable que en algún punto estén caídas. Por ello también dejo el pack con los estilos y el JQUERY para que lo puedas hospedar en tu servidor y las referencias las puedas modificar.

Descarga


¿Todo listo?

Ciertamente lo está el resultado es el siguiente.


Sin embargo, tener acceso fuera de la LAN, necesitas hacer un foward del puerto 80 (en caso que uses el http por defecto) a la IP local del Arduino. Cosa que puedas entrar desde un navegador externo ingresando la IP publica y el router automáticamente haga el request al arduino. Tambien puede resultar practico configurar un DNS dinámico en red, de manera que sea un poco más cómodo el acceso mediante un nombre fácil de recordar y no una IP.


Les dejo un vídeo demostrando la funcionalidad y como siempre, cualquier duda la pueden dejar en los comentarios.
