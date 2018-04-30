class Main inherits IO {
    a : String <- "Hello World!";
   main(): SELF_TYPE {
       {
            out_string(a);
            self;
       }
   };
};
