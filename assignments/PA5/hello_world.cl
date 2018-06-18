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

-- class A {
--     a : String;
--     getA() : String {
--         a
--     };
-- };

-- class Main inherits IO{
-- 	main():Object {{
-- 		-- if (true = false) then abort() else 0 fi;
-- 		-- if (true = true) then 0 else abort() fi;
-- 		-- if ("hello" = "hello".copy()) then 0 else abort() fi;
-- 		let a:A <- new A in if (a.getA() = "") then 0 else abort() fi;
-- 		-- if 5 = 6 then abort() else 0 fi;
-- 	}};

-- };


-- new SELF_TYPE creates an object with the same dynamic type as self,
-- which affects initialization of the new object's attributes.



-- (* hairy  . . .*)

-- class Second inherits First {};

-- class First inherits IO {

--     --  h : Int <- ({out_string("First::h\n"); 1;});

--      g : Second  <- case self of
-- 		     	n : First => ({out_string("First::First\n"); new Second;});
-- 				n : Second  => ({out_string("First::Second\n"); n;});
-- 		  		esac;

--     --  i : Object <- ({out_string("First::i\n");});

--     --  printh() : Int { { out_int(h); 0; } };

--     --  doh() : Int { (let i: Int <- h in { h <- h + 1; i; } ) };
-- };

-- (* scary . . . *)
-- class Main {
--   a : First <- new First;
-- --   b : Second <- new Second;
-- --   c : Third <- new Third;
-- --   d : Fourth <- new Fourth;

--   main(): String { "do nothing" };

-- };



-- (* hairy  . . .*)

-- class Foo inherits Bazz {
--      a : Razz <- case self of
-- 		      n : Razz => (new Bar);
-- 		      n : Foo => (new Razz);
-- 		      n : Bar => n;
--    	         esac;

--      b : Int <- a.doh() + g.doh() + doh() + printh();

--      doh() : Int { (let i : Int <- h in { h <- h + 2; i; } ) };

-- };

-- class Bar inherits Razz {

--      c : Int <- doh();

--      d : Object <- printh();
-- };


-- class Razz inherits Foo {

--      e : Bar <- case self of
-- 		  n : Razz => (new Bar);
-- 		  n : Bar => n;
-- 		esac;

--      f : Int <- a@Bazz.doh() + g.doh() + e.doh() + doh() + printh();

-- };

-- class Bazz inherits IO {

--      h : Int <- 1;

--      g : Foo  <- case self of
-- 		     	n : Bazz => (new Foo);
-- 		     	n : Razz => (new Bar);
-- 			n : Foo  => (new Razz);
-- 			n : Bar => n;
-- 		  esac;

--      i : Object <- printh();

--      printh() : Int { { out_int(h); 0; } };

--      doh() : Int { (let i: Int <- h in { h <- h + 1; i; } ) };
-- };

-- (* scary . . . *)
-- class Main {
--   a : Bazz <- new Bazz;
--   b : Foo <- new Foo;
--   c : Razz <- new Razz;
--   d : Bar <- new Bar;

--   main(): String { "do nothing" };

-- };


-- Dynamically dispatching on a void object is a runtime error.


-- class Main inherits IO
-- {
--   main() : Object
--   {
--     let nothing : Object <- while false loop 1 pool in
--       out_string(nothing.type_name())
--   };
-- };

class Main {
	x:Main;
	main():Object { { case x of m:Main => 0; esac; } };
};
