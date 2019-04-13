using System;
using System.Collections.Generic;
using System.Linq;
using Algorithms.Common;

namespace Algorithms.Sorting.BubbleSort
{
    public static class BubbleSort
    {
        public static IEnumerable<T> Sort<T>(this IEnumerable<T> collection) where T : IComparable<T>
        {
            var sorted = collection.ToArray();
            var max = sorted.Length;

            bool anySwap;
            do
            {
                anySwap = false;
                for (var i = 1; i < max; i++)
                {
                    if (sorted[i - 1].CompareTo(sorted[i]) > 0)
                    {
                        sorted.Swap(i, i - 1);
                        anySwap = true;
                    }
                }
                max--; //optimization
            } while (anySwap);

            return sorted;
        }
    }
}