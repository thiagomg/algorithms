using Algorithms.Test.Common;
using Algorithms.Test.Sorting;
using Algorithms.Trees;
using System;

namespace Algorithms.Test.Tree
{
    class TreeTraverseDepthFirstTests : ITestRun
    {
        public void Run()
        {
            Console.Write("Testing TreeTraverseDepthFirst... ");
            var tree = Helper.GenerateTree();
            var result = tree.Traverse();
            Assert.SequenceEqual(new[] { "C", "B", "D", "A", "E", "G", "F" }, result);
            Console.WriteLine("passed.");
        }
    }
}
