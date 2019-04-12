using System;
using Algorithms.Sorting.BubbleSort;
using Algorithms.Test.Common;

namespace Algorithms.Test.Sorting
{
    public static class BubbleSortTests
    {
        public static void Run()
        {
            Console.Write("Testing BubbleSort... ");
            var unsorted = Helper.GenerateUnsortedCollection();
            var sorted = unsorted.Sort();
            Assert.IsSorted(sorted);
            Console.WriteLine("passed.");
        }
    }
}