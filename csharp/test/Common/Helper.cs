using System;
using System.Collections;
using System.Linq;

namespace Algorithms.Test.Common
{
    static class Helper
    {
        /// <summary>
        /// Creates a collection of random number
        /// </summary>
        public static int[] GenerateUnsortedCollection()
        {
            int Min = 0;
            int Max = 10;
            Random randNum = new Random();
            return Enumerable
                .Repeat(0, Max)
                .Select(i => randNum.Next(Min, Max))
                .ToArray();
        }
    }
}