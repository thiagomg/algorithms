using System;
using System.Linq;

namespace Algorithms.Test.Common
{
    public static class Assert
    {
        /// <summary>
        /// Assert a collection is sorted
        /// </summary>
        public static void IsSorted<T>(System.Collections.Generic.IEnumerable<T> sorted) where T : IComparable<T>
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

    }
}