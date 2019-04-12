using System;
using System.Collections.Generic;
using System.Linq;
using Algorithms.Common;

namespace Algorithms.Sorting.InsertionSort
{
    public static class InsertionSort
    {
        public static IEnumerable<T> Sort<T>(this IEnumerable<T> collection) where T : IComparable<T>
        {
            var sorted = collection.ToArray();

            var i = 1;
            while (i < sorted.Length)
            {
                var j = i;
                while (j > 0 && sorted[j - 1].CompareTo(sorted[j]) > 0)
                {
                    sorted.Swap(j, j - 1);
                    j--;
                }
                i++;
            }

            return sorted;
        }

    }

}