using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodingTest
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("****************************************************");
            Console.WriteLine("Coding Test");
            Console.WriteLine("Ver 1.0.0");
            Console.WriteLine("Aug 02, 2021");
            Console.WriteLine("****************************************************");

            while (true)
            {
                PrintMenu();
                Console.WriteLine("[번호 선택(ESC 입력 시 프로그램 종료)]");
                ConsoleKeyInfo keyinfo = Console.ReadKey(true);
                if (keyinfo.Key == ConsoleKey.Escape)
                    break;

                switch (keyinfo.Key)
                {
                    case ConsoleKey.NumPad1:
                    case ConsoleKey.D1:
                        Console.Clear();
                        Call_LottoTest();
                        ContinueConsole();
                        break;

                    case ConsoleKey.NumPad2:
                    case ConsoleKey.D2:
                        Console.Clear();
                        Call_MiddleStr();
                        ContinueConsole();
                        break;

                    case ConsoleKey.NumPad3:
                    case ConsoleKey.D3:
                        Console.Clear();
                        Call_StrDesc();
                        ContinueConsole();
                        break;

                    case ConsoleKey.NumPad4:
                    case ConsoleKey.D4:
                        Console.Clear();
                        Call_WeiredCharacter();
                        ContinueConsole();
                        break;

                    case ConsoleKey.Escape:
                        return;
                }
            }
            

            

        }


        public static void PrintMenu()
        {
            Console.WriteLine("[1] 로또 최고 순위&최저 순위 맞추기");
            Console.WriteLine("[2] 가운데 문자열 반환");
            Console.WriteLine("[3] 문자열 내림차순 정렬");
            Console.WriteLine("[4] 이상한 문자");
            Console.WriteLine("==========================================");
        }

        public static void ContinueConsole()
        {
            Console.WriteLine("계속하려면 아무 키나 누르십시오 . . .");
            Console.ReadLine();
            Console.Clear();
        }




        public static void Call_LottoTest()
        {
            // Solution solution = new Solution();
            Solution solution = Solution.Instance();

            List<int[]> list_lottos = new List<int[]>();                     // 사용자 선택 로또번호 list
            List<int[]> list_wins = new List<int[]>();                       // 당첨번호 list

            // 사용자번호 set
            list_lottos.Add(new int[] { 44, 1, 0, 0, 31, 25 });
            list_lottos.Add(new int[] { 0, 0, 0, 0, 0, 0 });
            list_lottos.Add(new int[] { 20, 9, 3, 45, 4, 35 });

            // 당첨번호 set
            list_wins.Add(new int[] { 31, 10, 45, 1, 6, 19 });
            list_wins.Add(new int[] { 38, 19, 20, 40, 15, 25 });
            list_wins.Add(new int[] { 20, 9, 3, 45, 4, 35 });

            #region 사용자 번호 리스트 선택
            Console.WriteLine(list_lottos.Count.ToString() + "개의 [선택 번호]가 있습니다. 입력하세요.");
            Console.Write("입력 : ");
            int i_lottoSel = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("--------------------------------------------");
            Console.WriteLine("<<선 택 번 호(" + i_lottoSel + ")>>");
            for (int i = 0; i < list_lottos[i_lottoSel - 1].Length; i++)
            {
                Console.Write("[" + list_lottos[i_lottoSel - 1][i].ToString() + "]\t");
            }
            Console.WriteLine();
            Console.WriteLine();
            #endregion


            #region 당첨 번호 리스트 선택
            Console.WriteLine(list_wins.Count.ToString() + "개의 [당첨 번호]가 있습니다. 입력하세요.");
            Console.Write("입력 : ");
            int i_winSel = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("--------------------------------------------");

            Console.WriteLine("<<당 첨 번 호(" + i_winSel + ")>>");
            for (int i = 0; i < list_wins[i_winSel - 1].Length; i++)
            {
                Console.Write("[" + list_wins[i_winSel - 1][i].ToString() + "]\t");
            }
            Console.WriteLine();
            Console.WriteLine();
            #endregion


            // Output
            int[] arr_answer = Solution.Solution_lotto(list_lottos[i_lottoSel - 1], list_wins[i_winSel - 1]);

            Console.WriteLine("--------------------------------------------");
            Console.WriteLine("최고 순위 : " + arr_answer[0] + ", 최저 순위 : " + arr_answer[1]);
            Console.WriteLine("--------------------------------------------");
        }


        public static void Call_MiddleStr()
        {
            Console.WriteLine("문자열을 입력하세요.");
            Console.Write("입력 : ");



            string str = Console.ReadLine();

            int midSize = str.Length % 2;
            string answer = string.Empty;
            if(midSize == 1)
            {
                int strtPos = (str.Length / 2);
                answer = str.Substring(strtPos, 1);
                
            }
            else
            {
                int strtPos = (str.Length / 2) - 1;
                answer = str.Substring(strtPos, 2);
            }
            Console.WriteLine("answer : " + answer);
        }


        public static void Call_StrDesc()
        {
            Console.WriteLine("문자열을 입력하세요.(알파벳 대/소문자)");
            Console.Write("str : ");
            string str = Console.ReadLine();
            string rslt = Solution.solution_StrDesc(str);
            Console.WriteLine("rslt : " + rslt);
        }


        public static void Call_WeiredCharacter()
        {
            Console.WriteLine("문자열을 입력하세요. : ");
            string str = Console.ReadLine();
            string rslt = Solution.solution_WeirdWord(str);
            Console.WriteLine("rslt : " + rslt);
        }


    }
}

