using System;
using System.Collections.Generic;
using System.Linq;

namespace Algorithms.Test.Common
{
    public static class Assert
    {
        /// <summary>
        /// Assert a collection is sorted
        /// </summary>
        public static void IsSorted<T>(IEnumerable<T> sorted) where T : IComparable<T>
        {
            var previous = sorted.First();
            foreach (var item in sorted.Skip(1))
            {
                if (item.CompareTo(previous) < 0)
                {
                    throw new Exception($"Collection is not sorted. {item} is not greater than {previous}.");
                }
                previous = item;
            }
        }
        public static void SequenceEqual<T>(IEnumerable<T> expected, IEnumerable<T> actual)
        {
            if (!expected.SequenceEqual(actual))
            {
                throw new Exception("Sequences are not equal");
            }
        }
    }
}