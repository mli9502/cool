class Main inherits IO {
    a : Int <- 0;
   main(): SELF_TYPE {
       {
            hello(a);
       }
   };
   hello(a : Int) : SELF_TYPE { 
       {
           out_string("Hello World!\n");
            self;
       } 
    };
};
