using Algorithms.Trees.Model;
using System.Collections.Generic;

namespace Algorithms.Trees
{
    public static class DepthFirst
    {
        public static IEnumerable<string> Traverse(this Node node)
        {
            if (node == null) yield break;

            if (node.Left != null)
                foreach (var n in Traverse(node.Left)) yield return n;

            yield return node.Name;

            if (node.Right != null)
                foreach (var n in Traverse(node.Right)) yield return n;
        }
    }
}
