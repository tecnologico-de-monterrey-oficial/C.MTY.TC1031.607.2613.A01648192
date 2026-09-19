Brainstorm:
Tiene que haber un script para darle valor a cada dato y otro para sort. Posiblemente, un archivo para cada sort si queremos ser ordenados, pero no es necesario. ¿Qué diría Salinas?

Los datos vienen en la estructura:
Sep 29 2024 14:37:38 10.14.19.188 Unauthorized Access Attempts
mes, día, año, hora:minuto:segundo, ip, error
1. enumerar el mes día y año.
2. agarra los dos puntos el sort? si no, we're cooked.
3. lo mismo para el IP, pero en ese caso se tiene que llenar los espacios que no se han ocupado. Todos empiezan con 10.14, pero el siguiente número debería tener un "019" en vez de solo "19". En el excel fue muy fácil de ver eso.
4. ¿cuentan los espacios? no recuerdo si en el excel de la clase quitó los espacios en el error o no. En cualquier caso, eso no debería de estar muy difícl
5. Que se sepa desde ya que no voy a correr el código ni una vez sin pasarlo por Gemini para hacer debugging. No tendré Copilot encendido. He aquí mis sustentos: https://www.geeksforgeeks.org/cpp/logging-system-in-cpp/
6. Los algoritmos ya están bien y si no me equivoco, deberían correr las databses como está ahorita. El profe (¿creo que fue el profe? Pudo haber sido alguien de la clase) mencionó sobreescribir "<" y ">". En cualquier caso, eso tendría que ir dentro del logrecord para darles la jerarquía. ¿Podría ir en el sorting script también? Voy a leer más de eso. Sería ciertamente más conveniente para no tener que andar editando los algortimos ya existentes. ¿Hago otro .cpp para eso? Otra vez pensando en Salinas.
7. La función de lectura en main.
8. Problablemente voy a correr los databases primero en el folder de los algortimos de la tarea pasada para ver cuánto se tarda cada uno.
9. Por ahorita voy a llevar un desorden. Perdón. Ando exhausta, ahí lo organizo mañana.

For fun, mirar qué es B Tree lueguito


Instrucciones:
La app debe implementar todos los algoritmos de ordenamiento vistos en clase hasta la Actividad 1.5 (los cubiertos en el curso más el que agregaron en esa actividad) y, en cada corrida, dejar que el usuario elija cuál ejecutar.

Antes de cada corrida de ordenamiento, el flujo debe pedir al usuario:

    Sobre cuál archivo realizar el proceso: log607-1.txt (desordenado) o log607-2.txt (casi ordenado).
    Cuál algoritmo ejecutar, de entre todos los disponibles.
    Una predicción de qué tan rápido o lento espera que sea esa combinación específica de algoritmo + archivo, y por qué (tamaño de los datos, qué tan ordenado está el archivo elegido).

Después de ejecutar cada corrida, seguir mostrando y guardando lo mismo que ya se pedía:

    Nombre del algoritmo elegido.
    Archivo usado y tamaño de los datos.
    Tiempo de ejecución del ordenamiento.
    Complejidad teórica del algoritmo (mejor caso y peor caso), y si el resultado medido coincidió o no con la predicción inicial.

Generar output608.txt con los datos ordenados de la corrida más reciente (mismo formato del archivo original).

Punto B:
El flujo debe permitir repetir corridas (otro algoritmo, otro archivo, o ambos) sin reiniciar el programa, para poder comparar. Se espera que noten que no todos los algoritmos se benefician igual de un dataset casi ordenado.
Pedir fecha/hora inicio y fecha/hora fin (no es necesario que existan en el archivo).

    Realizar la selección del subrango mediante una técnica de búsqueda binaria (o equivalente en eficiencia — por ejemplo interpolation search o exponential search; si usan otra técnica, deben poder justificar que su costo es logarítmico o mejor).
    Mostrar en pantalla y guardar el resultado en range607.txt (mismo formato).
    Caso de borde obligatorio: log607-2.txt contiene timestamps duplicados a propósito. Su búsqueda debe definir y documentar qué hace cuando el límite de inicio o fin del rango coincide exactamente con uno o más registros, y no debe perder ni duplicar registros en ese caso.
