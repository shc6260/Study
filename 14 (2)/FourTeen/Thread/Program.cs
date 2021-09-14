using System;
using System.Threading;
namespace thread
{
    class Program
    {
        delegate ThreadStart();

        static void ThreadBody()
        {
            for (int i = 0; i <= 15; i++)
            {
                Console.WriteLine(DateTime.Now.Second + ":" + i);
                Thread.Sleep(1000);
            }
        }

        static void Main(string[] args)
        {
            ThreadStar ts = new ThreadStar(ThreadBody);

            Thread t = new Thread(ts);

            Console.WriteLine();

        }
    }
}
