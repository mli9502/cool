class Main inherits IO {
    a : Int <- 0;
    b : Int <- 1;
    c : Int <- 2;
    d : Int <- 3;
    e : Int <- 4;
   main(): SELF_TYPE {
       {
	out_string("Hello, World.\n");
    hello(a,b,c);
       }
   };
   hello(a : Int, b : Int, c : Int) : SELF_TYPE { 
       {
           a + b;
            self;
       } 
    };
};
