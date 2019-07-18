using System;
using Algorithms.Sorting.InsertionSort;
using Algorithms.Test.Common;

namespace Algorithms.Test.Sorting
{
    class InsertionSortTests : ITestRun
    {
        public void Run()
        {
            Console.Write("Testing InsertionSort... ");
            var unsorted = Helper.GenerateUnsortedCollection();
            var sorted = unsorted.Sort();
            Assert.IsSorted(sorted);
            Console.WriteLine("passed.");
        }
    }
}