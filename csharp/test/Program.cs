using Algorithms.Test.Sorting;
using System;
using System.Linq;

namespace Algorithms.Test
{
    class Program
    {
        static void Main(string[] args)
        {
            var type = typeof(ITestRun);
            var tests = AppDomain.CurrentDomain.GetAssemblies()
                .SelectMany(s => s.GetTypes())
                .Where(p => p.GetInterfaces().Contains(type));

            foreach (var test in tests)
            {
                var obj = (ITestRun)Activator.CreateInstance(test);
                try
                {
                    obj.Run();
                }
                catch (Exception ex)
                {
                    Console.WriteLine($"Test failed. Exception: {ex.Message}");
                }
            }            
        }
    }
}
