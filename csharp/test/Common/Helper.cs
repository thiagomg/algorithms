using Algorithms.Trees.Model;
using System;
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

        public static Node GenerateTree()
        {
            return new Node
            {
                Name = "A",
                Left = new Node
                {
                    Name = "B",
                    Left = new Node { Name = "C" },
                    Right = new Node { Name = "D" }
                },
                Right = new Node
                {
                    Name = "E",
                    Right = new Node
                    {
                        Name = "F",
                        Left = new Node { Name = "G" }
                    }
                }
            };
        }
    }
}