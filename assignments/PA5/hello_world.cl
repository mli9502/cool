class Main inherits IO {
    a : String <- "Hello World!\n";
   main(): SELF_TYPE {
       {
            out_string(a);
            self;
       }
   };
};
