class Main inherits IO {
    a : A <- new B;
    y : Int <- 0;
    main(): SELF_TYPE {
        {
            -- (let position : Int <- 1 in
            --     {
            --         (let num : Int <- 2 in
            --             (let temp : String <- "temp" in
            --                 {
            --                     out_int(position);
            --                     out_string("\n");
            --                     out_int(num);
            --                     out_string("\n");
            --                     out_string(temp);
            --                     out_string("\n");
            --                 }
            --             ) 
            --         );
            --         out_string("first let\n");
            --         out_int(position);
            --         out_string("\n"); 
            --     }
                
            -- );

	       out_string((isvoid self).type_name().substr(3, 1));
           out_string("\n");
           self;

            -- a.ma(1, 2);
            -- out_int((new A).ma(3, 4));
            -- out_string("\n");
            -- self;
        }
    };
};

class A inherits IO {
    a : Int <- 10;
    getA() : Int {
        a
    };
    ma(i: Int, j: Int) : Int {
        {
            out_string("A::i: ");
            out_int(i);
            out_string("\nA::j: ");
            out_int(j);
            out_string("\n");
            a;
        }
    };
};
class B inherits A {
    ma(i: Int, j: Int) : Int {
        {
            out_string("B::i: ");
            out_int(i);
            out_string("\nB::j: ");
            out_int(j);
            out_string("\n");
            a;
        }
    };
};
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
