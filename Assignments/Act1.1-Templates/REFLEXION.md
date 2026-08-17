¿Qué ventaja concreta notaste al usar templates en tu clase Lista, comparado con haberla hecho solo para un tipo de dato (por ejemplo, solo enteros)? Da un ejemplo de tu propio código.
    Mucho más eficiente, y además se ahorran muchísimas líneas de código que viene siendo muy valioso al trabajar en códigos más complejos. Se resume muy bien en esta parte que hicimos en clase:
        /*
        int sum(int a, int b){
            return a+b;
        }

        double sum(double a, double b){
            return a+b;
        }

        string sum(string a, string b){
            return a+b;
        }
        */

        template <typename T>
        T sum(T a, T b) {
            return a + b;
        }

    donde los tres primeros segmentos que están encapsulados como comentario pueden ser resumidos en el template de abajo. Está muy cool para agilizar código. Igualmente, se ocupa la misma template en mi código para ambas listas:
     cout<<"\nlista de strings"<<endl;
    List<string> things;
    things.insert("Laptop");
    things.insert("Bottle");
    things.print();

        cout<<"lista de #"<<endl;
        //insertar
        myList.insert(7);
        myList.insert(27);
        myList.insert(43);
        myList.print();

¿Qué parte de la actividad —ya sea el uso de templates o el reto de insertAt/removeAt— te costó más trabajo entender o depurar? ¿Qué hiciste para resolverlo?
    Lo que más me costó fue, quizás, estructurar el código de la manera correcta. Mi profesor previo era extremadamente estricto 
    con los contenidos de cada archivo, entonces traté de poner las funciones dentro del act1.1-Templates.cpp y dejar el List.h sólo como definición de Class. Me causó muchos problemas y no corrió hasta que puse las funciones en el List.h
    Le mandé mi código posteriormente a Gemini y me dijo que faltaban unas líneas de código que no hemos visto en clase, entonces decidí mejor apegarme a lo enseñado este semestre, pero sí gasté mucho tiempo tratando de adherirme a la estructura que ya conocía. Esto sin mencionar que por un ratito había pensado en incluir pointers.

    Luego, otro pedacito que también me tardó más de lo pensado fue figurar qué hacer si la lista estaba vacía (me tiraba segmetation fault por lo de max value), y al final fue tan simple como pedir que regresara un vacío si no habían valores en la lista.

Si tuvieras que explicarle a un compañero qué es un template en C++ usando tus propias palabras, sin tecnicismos, ¿qué le dirías?
    Un template es una función que se unirsalisa, por así decirlo, para que pueda ser ocupada con diversos tipos de datos. Al cambio de poner el tipo de datos, pones <T>, y la compu rellena esa información con el tipo de dato que se le de.