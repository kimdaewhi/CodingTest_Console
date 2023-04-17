using System.Data;

namespace CodingTest
{
    class Solution
    {
        private static Solution _instance;
        public static Solution Instance()
        {
            if (_instance == null)
            {
                _instance = new Solution();
            }
            return _instance;
        }




        /// <summary>
        /// 로또 최고순위&최저순위 구하기
        /// </summary>
        /// <param name="lottos"></param>
        /// <param name="win_nums"></param>
        /// <returns></returns>
        public static int[] Solution_lotto(int[] lottos, int[] win_nums)
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


        /// <summary>
        /// 문자열 내림차순 정렬
        /// https://school.programmers.co.kr/learn/courses/30/lessons/12917?language=csharp
        /// </summary>
        /// <param name="s">입력 문자열</param>
        /// <returns></returns>
        public static string solution_StrDesc(string s)
        {
            string answer = string.Empty;
            string str = s;
            char[] strArr = str.ToCharArray();
            for(int i = 0; i < strArr.Length - 1; i++)
            {
                for(int j = 0; j < strArr.Length - i - 1; j++)
                {
                    if(strArr[j] < strArr[j + 1])
                    {
                        char temp = strArr[j];
                        strArr[j] = strArr[j + 1];
                        strArr[j + 1] = temp;
                    }
                }
            }
            answer = new string(strArr);
            return answer;
        }


        /// <summary>
        /// 이상한 문자 만들기
        /// https://school.programmers.co.kr/learn/courses/30/lessons/12930?language=csharp
        /// 문자열이 짝수번째면 대문자, 홀수번째면 소문자로 변환
        /// 단, 첫 글자는 짝수번째로 인식(index = 0)
        /// 각 문자열의 구분자는 공백(' ')으로 인식
        /// </summary>
        /// <param name="s">문자열</param>
        /// <returns></returns>
        public static string solution_WeirdWord(string s)
        {
            string answer = string.Empty;

            for(int i = 0; i < s.Split(' ').Length; i++)
            {
                char[] tempChar = s.Split(' ')[i].ToCharArray();
                for(int j = 0; j < tempChar.Length; j++)
                {
                    if( (j % 2 == 0) && System.Char.IsLower(tempChar[j]) )
                    {
                        tempChar[j] = System.Char.ToUpper(tempChar[j]);
                    }
                    else if( (j % 2 == 1) && System.Char.IsUpper(tempChar[j]) )
                    {
                        tempChar[j] = System.Char.ToLower(tempChar[j]);
                    }
                }
                answer += new string(tempChar) + " ";
            }
            answer = answer.Substring(0, answer.Length - 1);

            return answer;
        }


    }
}
