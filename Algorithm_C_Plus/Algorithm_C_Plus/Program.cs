using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Algorithm_C_Plus
{
    enum SORT_TYPE
    {
        QUICK_SORT = 0,         // 快速排序
        SELECT_SORT,            // 选择排序
        MAOPAO_SORT,            // 冒泡排序
    };

    enum SORT_UP_DOWN
    {
        SORT_UP = 0,            // 递增排序
        SORT_DOWN,              // 递减排序    
    };

    enum SORT_TIME
    {
        SORT_BEFORE = 0,        // 排序前
        SORT_AFTER,             // 排序后      
    };

    class Program
    {
        public void PrintSortValue(int[] arrySortValue, SORT_TYPE eSortType, SORT_UP_DOWN eSortUpDown, SORT_TIME eSortTime)
        {
            String[] strSortType = {"快速","选择","冒泡"};
            String[] strSortUpDown = { "递增", "递减" };
            String[] strSortTime = { "排序前", "排序后" };
            Console.WriteLine("{0:G}{1:G}{2:G}", strSortType[(int)eSortType], strSortUpDown[(int)eSortUpDown], strSortTime[(int)eSortTime]);
            foreach (var value in arrySortValue)
            {
                Console.Write("{0:G}{1:G}", value.ToString(), "   ");
            }
            Console.Write("\n");
        }

        static void Main(string[] args)
        {
            Program prog = new Program();
            int [] arryQuickSort = new int[] { 0, 49, 86, 9, 6, 5, 6969, 89, 75, 6, 999 };
            prog.PrintSortValue(arryQuickSort, SORT_TYPE.QUICK_SORT, SORT_UP_DOWN.SORT_UP, SORT_TIME.SORT_BEFORE);
            Console.ReadKey();
        }
    }
}
