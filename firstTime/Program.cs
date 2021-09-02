using System; //Se tiver u use system não há necessidade de utilizar o system antes do console
using System.Collections.Generic;
//shift + alt + f

namespace WorkSpace___RR //Name space é opcional
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello it's me the good advice cupcake!\n");
            System.Console.WriteLine("Boa tarde");

            bool boolean = true;
            char genero = 'F';
            char letra = '\u0041';
            byte n1 = 126;

            object[] vetor = new object[12]; //Vetor
            var list = new List<object>();

            vetor[0] = boolean;
            list.Add(boolean);
            SByte x = 110; //Agrega valores de -128 até 127
            //byte n1 = 126; //Aceita números de 0 a 255
            Console.WriteLine(x);
            Console.WriteLine(n1);

            foreach(object o in vetor)
                Console.WriteLine(o);

            Console.WriteLine("\n------------------\n");

            foreach(object o in list)
                Console.WriteLine(o);
        }
    }
}
