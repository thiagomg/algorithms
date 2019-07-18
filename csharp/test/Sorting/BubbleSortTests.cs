using System;
using Algorithms.Sorting.BubbleSort;
using Algorithms.Test.Common;

namespace Algorithms.Test.Sorting
{
    class BubbleSortTests : ITestRun
    {
        public void Run()
        {
            Console.Write("Testing BubbleSort... ");
            var unsorted = Helper.GenerateUnsortedCollection();
            var sorted = unsorted.Sort();
            Assert.IsSorted(sorted);
            Console.WriteLine("passed.");
        }
    }
}