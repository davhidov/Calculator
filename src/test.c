#include <check.h>

#include "s21_SmartCalc/input.h"

START_TEST(calc_test_1) {
  {
    char *arr[] = {
        ")5+7(",
        "(",
        "()",
        "()*()*()",
        "(()*())",
        "))",
        "((",
        "(()",
        "(()())()",
        "(()()()",
        "(1)(-)(2)",
        "((+x-)*(x))",
        "((1)(2)(3)",
        "(1)*((-)2)*(3)",
        "(1)(-x)(1)",
        "aoa",
        "x.",
        ".",
        ",",
        ".0",
        ".575",
        "--5",
        ".5.5.",
        "....",
        "..",
        //"5.5.5",
        //"5.5 5.5",
        "5*5. * 5",
        //"5   5",
        "log(x)ln(x)",
        //"a(x)",
        "co sin",
        "co s(x)",
        "as(x)",
        "cos( x + 23 / 3 ) - 255 ln(x)",
        "cos( x + 23 / 3 ) - 255log(x)",
        "cos( x + 23 / 3 ) - log(x)255",
        "sin(*8)",
        //"l(x)",
        "ll(x)",
        "",
        "(*5)",
        "(/5)",
        "(^5)",
        "(mod5)",
        "()",
        "(.5)",
        "(555+)",
        "(555-)",
        "(555*)",
        "(5555/)",
        "(555mod)",
        "(555()",
        "(555.)",
        "7(+3)",
        "*3+3",
        "())",
        "lod(33)",
        "2*+6",
    };
    Graf g;
    int NumElements = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < NumElements; i++) {
      double x = 1.8;
      // g.rez = 0;
      int CODE = draw(arr[i], &g, 0, x, 0);
      ck_assert_int_eq(CODE, 1);
      // ck_assert_double_eq(g.rez, 0);
    }
  };
}
END_TEST

START_TEST(calc_test_2) {
  {
    double x = 1.8;
    char *arr[] = {
        "2+0.2",
        "xmod(-4)",
        "x^(-4)",
        "255*x*(-255)",
        "-2+5",
        "-sqrt(100)",
        "(20*(-2))",
        "3+(-sqrt(100))",
        "-(-(-2))",
        "sin(-2)",
        "-2^2",
        "-(-(-log(100000)))",
        "22-(-2^3)",
        "sin(-2+3)",
        "-2+3+3",
        "2-(-(-(-(4*log(100)*3/3+100))))",
        "22*1",
        "5",
        "5.5",
        "5.5 * 5",
        "45",
        "(x)",
        "((1)*(55))*(3)",
        "ln(10)",
        "ln(1)",
        "cos(x) * sin(x) *tan(x)",
        "(acos(1))* asin(1)",
        "sqrt(x)",
        "ln(x)",
        "x mod x",
        "x mod 5",
        "sin( x + 2 / 3) / (4 mod 5) ",
        "sin( x + ln(2) ^ 3 ) / (4*5)",
        "255*x*(-255)",
        "2+5",
        "sqrt(100)",
        "(20*(2))",
        "3*sqrt(25)",
        "sqrt((24*1)+1)",
        "3+(sqrt(100))",
        "(2)",
        "sin(2)",
        "2^2",
        "(((log(100000))))",
        "22-(2^3)",
        "atan(0.5)",
        "+1000mod994",
        "2-cos(3)",
        "sin(2+3)",
        "2+3+3",
        "2-((((4*log(100)*3/3+100))))",
        "tan(asin(1))",
        "ln(acos(0))",
        "2+2.4",
        "2/(1+2)",
        "1000mod994",
        "2^3^4",
        "2^(3^4)",
        "(2^3)^4",
        "2*3mod4",
        "33-5*x",
        "5",
    };
    double ResultNumbers[] = {
        2 + 0.2,
        fmod(x, -4),
        pow(x, -4),
        255 * x * (-255),
        -2 + 5,
        -sqrt(100),
        (20 * (-2)),
        3 + (-sqrt(100)),
        -(-(-2)),
        sin(-2),
        -2 ^ 2,
        -(-(-log10(100000))),
        22 - (-8),
        sin(-2 + 3),
        -2 + 3 + 3,
        2 - (-(-(-(4 * log10(100) * 3 / 3 + 100)))),
        22 * 1,
        5,
        5.5,
        5.5 * 5,
        45,
        (x),
        ((1) * (55)) * (3),
        log(10),
        log(1),
        cos(x) * sin(x) * tan(x),
        (acos(1)) * asin(1),
        sqrt(x),
        log(x),
        fmod(x, x),
        fmod(x, 5),
        sin(x + 2. / 3.) / (fmod(4, 5)),
        sin(x + pow(log(2), 3)) / (4 * 5),
        255 * x * (-255),
        2 + 5,
        sqrt(100),
        (20 * (2)),
        3 * sqrt(25),
        sqrt((24 * 1) + 1),
        3 + (sqrt(100)),
        (2),
        sin(2),
        2 * 2,
        (((log10(100000)))),
        22 - (2 * 2 * 2),
        atan(0.5),
        fmod(+1000, 994),
        2 - cos(3),
        sin(2 + 3),
        2 + 3 + 3,
        2 - ((((4. * log10(100) * 3. / 3. + 100.)))),
        tan(asin(1)),
        log(acos(0)),
        2 + 2.4,
        (2. / 3.),
        fmod(1000, 994),
        pow(8, 4),
        pow(2, pow(3, 4)),
        pow(8, 4),
        fmod(2 * 3, 4),
        33 - 5 * x,
        5,
    };
    Graf g;
    int NumElements = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < NumElements; i++) {
      g.rez = 6;
      int CODE = draw(arr[i], &g, 0, x, 0);
      ck_assert_int_eq(CODE, 0);
      ck_assert_double_eq_tol(g.rez, ResultNumbers[i], 1e-7);
    }
  };
}
END_TEST

START_TEST(calc_test_3) {
  {
    char *arr[] = {"cos(x) * sin(x) *tan(x) *(-acos(x))* asin(x)", "ln(-1)"};
    int NumElements = sizeof(arr) / sizeof(arr[0]);
    Graf g;
    for (int i = 0; i < NumElements; i++) {
      double x = 1.8;
      g.rez = 6;
      int CODE = draw(arr[i], &g, 0, x, 0);
      ck_assert_int_eq(CODE, 0);
      ck_assert_double_nan(g.rez);
    }
  };
}
END_TEST

START_TEST(calc_test_4) {
  {
    char *arr[] = {
        "2/0",
        "2/(2-2)",
    };
    int NumElements = sizeof(arr) / sizeof(arr[0]);
    Graf g;

    for (int i = 0; i < NumElements; i++) {
      double x = 1.8;
      g.rez = 6;
      int CODE = draw(arr[i], &g, 0, x, 0);
      ck_assert_int_eq(CODE, 0);
      ck_assert_double_infinite(g.rez);
    }
  };
}
END_TEST
int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  suite_add_tcase(s1, tc1_1);

  tcase_add_test(tc1_1, calc_test_1);
  tcase_add_test(tc1_1, calc_test_2);
  tcase_add_test(tc1_1, calc_test_3);
  tcase_add_test(tc1_1, calc_test_4);

  srunner_run_all(sr, CK_ENV);
  int nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}