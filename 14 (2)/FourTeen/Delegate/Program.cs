using System;

namespace Delegate
{
    delegate int MyDelegate(int a, int b); //대리자 선언

    class Calculator
    {
        public int Plus(int a , int b) //대리자는 인스턴스 메서드 참조
        {
            return a + b;
        }
        public static int Minus(int a, int b) //대리자는 정적 메서드 참조
        {
            return a - b;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Calculator C = new Calculator();
            MyDelegate Callback; // MyDelegate 대리자의 인스턴스

            Callback = new MyDelegate(C.Plus);
            //대리자의 인스턴스를 만들 때도 new 연산자 필요
            //대리자를 메서드 호출하듯 사용하면 , 참조하고 있는 메서드가 실행됨

            Console.WriteLine(Callback(3, 4));

            Callback = new MyDelegate(Calculator.Minus);
            Console.WriteLine(Callback(7, 5));

        }
    }
}
