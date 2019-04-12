using System.Collections.Generic;

namespace Algorithms.Common
{
    public static class SortHelper
    {
        public static void Swap<T>(this IList<T> array, int firstIndex, int secondIndex)
        {
            var temp = array[firstIndex];
            array[firstIndex] = array[firstIndex - 1];
            array[firstIndex - 1] = temp;
        }
    }
}
