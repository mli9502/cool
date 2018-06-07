-- class Main inherits IO {
--     a : A <- new B;
--     y : Int <- 0;
--     main(): SELF_TYPE {
--         {
--             -- ************************************
--             -- Test let expression...
--             -- (let position : Int <- 1 in
--             --     {
--             --         (let num : Int <- 2 in
--             --             (let temp : String <- "temp" in
--             --                 {
--             --                     out_int(position);
--             --                     out_string("\n");
--             --                     out_int(num);
--             --                     out_string("\n");
--             --                     out_string(temp);
--             --                     out_string("\n");
--             --                 }
--             --             ) 
--             --         );
--             --         out_string("first let\n");
--             --         out_int(position);
--             --         out_string("\n"); 
--             --     }
--             -- );
--             -- ************************************

--             -- ************************************
--             -- Test isvoid, type_name and dispatch to method in trap_handler.
--             out_string((isvoid self).type_name());
--             out_string("\n");
--             out_string((isvoid self).type_name().substr(1, 3));
--             out_string("\n");
--             self;
--             -- ************************************

--             -- ************************************
--             -- Test dynamic dispatch.
--             a.ma(1, 2);
--             out_int((new A).ma(3, 4));
--             out_string("\n");
--             self;
--             -- ************************************

--             -- ************************************
--             -- Test case.
--             case a of
--                 a_A : A => {
--                     out_string("class type is now A\n");
--                 };
--                 a_B : B => {
--                     out_string("class type is now B\n");
--                     case a of
--                         a_B_A : A => out_string("a_B_A\n");
--                         a_B_B : B => {
--                             (let position : Int <- 1 in
--                                 {
--                                     (let num : Int <- 2 in
--                                         (let temp : String <- "temp" in
--                                             {
--                                                 out_int(position);
--                                                 out_string("\n");
--                                                 out_int(num);
--                                                 out_string("\n");
--                                                 out_string(temp);
--                                                 out_string("\n");
--                                             }
--                                         ) 
--                                     );
--                                     out_string("first let\n");
--                                     out_int(position);
--                                     out_string("\n"); 
--                                     a_B.ma(2, 3);
--                                     a_B_B.ma(1, 4);
--                                 }
--                             );    
--                         };
--                         a_B_O : Object => out_string("a_B_O\n");
--                     esac;
--                 };
--                 a_O : Object => out_string("class type is Object\n");
--             esac;
--             self;
--             -- ************************************
--         }
--     };
-- };

-- class A inherits IO {
--     a : Int <- 10;
--     getA() : Int {
--         a
--     };
--     ma(i: Int, j: Int) : Int {
--         {
--             out_string("A::i: ");
--             out_int(i);
--             out_string("\nA::j: ");
--             out_int(j);
--             out_string("\n");
--             a;
--         }
--     };
-- };
-- class B inherits A {
--     ma(i: Int, j: Int) : Int {
--         {
--             out_string("B::i: ");
--             out_int(i);
--             out_string("\nB::j: ");
--             out_int(j);
--             out_string("\n");
--             a;
--         }
--     };
-- };
-- class A {
--     m() : Int {
--         {
--             let x : Int in {
--                 0;
--             };
--         }
--     };
-- };

-- class B inherits A {
--     m() : Int {
--         {
--             let x : Int in {
--                 let y : Int in {
--                     0;
--                 };
--             };
--         }
--     };
-- };


-- class D inherits B {
--     m() : Int {
--         {
--             let x : Int in {
--                 let y : Int in {
--                     let z : Int in {
--                         0;
--                     };
--                 };
--             };
--         }
--     };
-- };


-- class E inherits B {
--     m() : Int {
--         {
--             let x : Int in {
--                 let y : Int in {
--                     let z : Int in {
--                         let xx : Int in {
--                             0;
--                         };
--                     };
--                 };
--             };
--         }
--     };
-- };

-- class C inherits A {
--     m() : Int {
--         {
--             let x : Int in {
--                 let y : Int in {
--                     let z : Int in {
--                         let xx : Int in {
--                             let yy : Int in {
--                                 0;
--                             };
--                         };
--                     };
--                 };
--             };
--         }
--     };
-- };


class Main inherits IO {
  f(x : Int, y : Int) : Object { {
    out_string("x: ");
    out_int(x);
    out_string("\ny: ");
    out_int(y);
    out_string("\n");
  } };
  main() : Object {
    let x : Int <- 2 in {
      f(x <- 3, x <- 4);
      out_int(x);
    }
  };
};
