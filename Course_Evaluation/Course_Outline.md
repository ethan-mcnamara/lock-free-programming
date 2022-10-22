# SENG 490: Directed Studies: Lock-Free Programming

_Ethan McNamara & Dr. Sean Chester_
_Fall 2022_

## Course Overview

The year 2003 marked a critical pivot in computing: processor clock speeds stopped accelerating at the exponential pace that had been observed since the 70's. Heat dissipation, power consumption, and current leakage all transpired to make it uneconomical to continue increasing processor frequencies, leading chip manufacturers to focus on concurrency [Sut05]. However, concurrency is generally considered to be hard: compared to sequential execution models, which follow a strict logical sequence of operations, modern, multiprocessor systems are _inherently asynchronous_, which makes the state of shared, mutable data structures highly unpredictable [HS08]. We need to reason about not just correct logic, but also possible worlds of probablistic events.

To make matters more challenging yet, standard techniques for managing concurrency involve locks, i.e., a zone of mutual exclusion that _temporarily prevents concurrency_. Managed poorly, these can lead to issues of deadlocking and starvation that compromise the efficiency that concurrency was meant to facilitate [HS08]. On the other hand, there are a number of _non-blocking_ techniques, the use of which is often referred to as _lock-free programming_, that, in the words of Herb Sutter, equate to "juggling razorblades."

This course investigates such non-blocking techniques from four perspectives: a) how do we _design software_ that uses non-blocking techniques to guarantee liveness of concurrent programs; b) how do we _prove correctness_ of a non-blocking algorithm; c) how do we perform _software testing_ on an implementation that uses non-blocking techniques; and d) how do we _experimentally validate_ that our concurrent application actually delivers improved performance.

## Intended Learning Outcomes for the Course

This course is meant to develop a combination of research skills and advanced content knowledge on developing applications with concurrency. In particular, after this course, you can:

1. When asked, differentiate wait-free, lock-free, and blocking algorithms in terms of their guarantees for safety and liveness.
2. Given a concurrent application, prove theoretical correctness using the concept of linearisability [HW90] .
3. Given a problem statement, design a provably correct multi-threaded software application that can leverage non-blocking algorithmic techniques, such as atomic fetches, CAS loops and load-link/store-conditionals.
4. Given a multi-threaded application, design a set of experiments (or tests) to verify correctness of the implementation in a multi-threaded context.
5. Given a series of advanced lectures aimed at graduate students and/or senior practitioners, synthesise the content in a manner that you can incorporate into your own Software Engineering practice for self-directed professional development.

## Deliverables

The course will consist of four deliverables:
- a literature review
- an interim report
- a final report
- a presentation and/or demo

The due dates and relative weights of these deliverables are as per the table below:

| **Deliverable** | **Weight** | **Due** |
|-----------------|------------|---------|
| Lit Review      | 20%        | 21 Oct  |
| Interim Report  | 25%        | 21 Nov  |
| Final Report    | 35%        | 21 Dec  |
| Presentation    | 20%        | 21 Dec  |

The _literature review_ will, by summarising and synthesising a set of assigned readings and video recordings, explain what are non-blocking algorithms, how we establish their correctness (in terms of both safety *and* liveness), and what guidelines we should follow in terms of selecting between them and lock-based methods based on, for example, mutual exclusion. It will also describe one or two case studies, such as well-known lock-free, thread-safe data structures, including how they address the classic ABA problem.

The _interim report_ will describe the software design of a complex multi-threaded application that involves synchronisation of multiple objects. It will also describe at least two approaches to coordinating access to shared resources, one based on locking and one that is non-blocking, together with a proof of correctness (probably based on linearisability [HW90]) for both algorithms. Moreover, it will describe the design of an experiment to evaluate prototype implementations of each approach, in terms of both efficiency and implementation correctness.

The _final report_ will moreover report experiment results comparing the blocking and non-blocking algorithms. It will depend on the creation of a prototype implementation, almost certainly in a systems-oriented language like C++.

The _presentation_ will report on this project's results, including both the theoretical analysis from the interim report and the empirical findings in the final report.


## References

[HS08] Herlihy & Shavit. (2008). _The Art of Multiprocessor Programming_. Morgan Kaufmann Publishers, Burlington MA.

[HW90] Herlihy & Wing. (1990). "Linearizability: a correctness condition for concurrent objects." _ACM Transactions on Programming Languages and Systems_ 12(3), 463–492.

[Pik15] Fedor Pikus. (2015). "CppCon 2015: Fedor Pikus PART 1 “Live Lock-Free or Deadlock (Practical Lock-free Programming)." Video. (9 October 2015). Retrieved 15 october 2022 from: https://youtu.be/lVBvHbJsg5Y.

[Sco19] Michael Scott. (2019). "Michael Scott — Nonblocking data structures. Part 1." Video. (14 October 2019). Retrieved 15 october 2022 from: https://youtu.be/9XAx279s7gs.

[Sut05] Sutter (2005). "The Free Lunch Is Over: A Fundamental Turn Toward Concurrency in Software." _Dr. Dobb's Journal_: 30(3). http://www.gotw.ca/publications/concurrency-ddj.htm

[Sut14] Herb Sutter. (2014). "CppCon 2014: Herb Sutter "Lock-Free Programming (or, Juggling Razor Blades), Part I." Video. (16 October 2014). Retrieved 15 october 2022 from: https://youtu.be/c1gO9aB9nbs.

[van18] Tony van Eerd. (2018). "Introduction to Lock-free Programming - Tony van Eerd." Video. (24 September 2018). Retrieved 15 october 2022 from: https://youtu.be/RWCadBJ6wTk.
