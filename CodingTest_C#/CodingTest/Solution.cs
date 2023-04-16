using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodingTest
{
    class Solution
    {
        public Solution() { }




        /// <summary>
        /// 로또 최고순위&최저순위 구하기
        /// </summary>
        /// <param name="lottos"></param>
        /// <param name="win_nums"></param>
        /// <returns></returns>
        public int[] Solution_lotto(int[] lottos, int[] win_nums)
        {
            int[] answer = new int[2] { 0, 0 };

            int oCnt = 0;               // 현재 당첨 개수
            int zeroCnt = 0;            // 지워진 숫자 개수

            int maxResult = 0;            // 최종 당첨갯수(최고순위)
            int minResult = 0;            // 최종 당첨갯수(최저순위)


            // 1. 현황파악
            for (int i = 0; i < lottos.Length; i++)
            {
                // 지워진 숫자 개수 파악
                if (lottos[i] == 0)
                {
                    zeroCnt++;
                }

                // 현재 추첨번호와 당첨번호 개수 파악
                for (int j = 0; j < win_nums.Length; j++)
                {
                    if( lottos[i] != 0 && lottos[i] == win_nums[j] )
                    {
                        oCnt++;
                    }
                }
            }

            // 2. 최고순위, 최저순위 구하기
            minResult = oCnt;

            switch (zeroCnt + oCnt)
            {
                case 6: maxResult = 1; break;
                case 5: maxResult = 2; break;
                case 4: maxResult = 3; break;
                case 3: maxResult = 4; break;
                case 2: maxResult = 5; break;
                case 1: maxResult = 6; break;
                case 0: maxResult = 6; break;
            }

            switch (oCnt)
            {
                case 6: minResult = 1; break;
                case 5: minResult = 2; break;
                case 4: minResult = 3; break;
                case 3: minResult = 4; break;
                case 2: minResult = 5; break;
                case 1: minResult = 6; break;
                case 0: minResult = 6; break;
            }

            answer[0] = maxResult;
            answer[1] = minResult;


            return answer;
        }

    }
}
