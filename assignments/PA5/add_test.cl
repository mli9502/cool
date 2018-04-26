class Main inherits IO {
    a : Int <- 6 + 7;
    b : Int <- 1;
    c : Int <- 2;
   main(): Main {
       {
            (new A).test;
            b <- 3;
            new Main;
       }
   };
};

class A {
      test : Int <- 2;
};
