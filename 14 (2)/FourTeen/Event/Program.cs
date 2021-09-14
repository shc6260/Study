using System;

namespace Event
{
    delegate void EventHandler(string message); // 대리자 선언

    class MyNotifier
    {
        public event EventHandler SometingHappened; // 대리자의 인스턴스

        public void DoSomething(int number)
        {
            int temp = number % 10;
            if (temp != 0 && temp % 3 == 0)
            {
                SometingHappened(String.Format("{0} , 짝", number));
                //3,6,9로 끝나는 값이 될때마다 이벤트가 발생
            }
        }

    }

    class Program
    {
        static public void MyHandler(string message)//이벤트 핸들러 작성
        {
            Console.WriteLine(message);
        }

        static void Main(string[] args)
        {
            //클래스의 인스턴스를 생성하고 , 이 객체의 이벤트에 이벤트 핸들러를 등록
            MyNotifier notifier = new MyNotifier();
            notifier.SometingHappened += new EventHandler(MyHandler);
            for(int i = 1; i<30; i++)
            {
                notifier.DoSomething(i);
            }
          
        }
    }
}
