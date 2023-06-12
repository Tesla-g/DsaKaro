class Solution
{
    public:
        double myPow(double x, int n)
        {
            long long int t = n;
            double mul = x;
            double res = 1;
            double threshold = 1e-6;

            if (t == INT_MAX && mul < 0 && abs(mul) == 1)
            {

                return -1;
            } 

            if (t == INT_MIN && mul < 0 && abs(mul) == 1)
            {

                return 1;
            }
            if (t == INT_MAX)
            {
                if (floor(mul) == 0)
                {
                    return 0;
                }
                else
                {
                    return 1;
                }
            }

            if (t == INT_MIN)
            {
                if (floor(mul == 1))
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }

            if (t > 0)
            {
                while (t >= 1)
                {
                    res = mul * res;
                    t--;
                }
            }
            else
            {
                int abst = abs(t);
                double newvalue = 0;
                while (abst >= 1)
                {
                    res = mul * res;
                    abst--;
                }
                res = (1 / res);
            }

            return res;
        }
};