# SENG 490: Literature Survey Assignment

## Objective

This first assignment should describe the background knowledge required for this project. It focuses on the following course learning outcomes:


1. When asked, differentiate wait-free, lock-free, and blocking algorithms in terms of their guarantees for safety and liveness.
2. Given a concurrent application, prove theoretical correctness using the concept of linearisability [HW90].
5. Given a series of advanced lectures aimed at graduate students and/or senior practitioners, synthesise the content in a manner that you can incorporate into your own Software Engineering practice for self-directed professional development.


## Specifications

You should prepare a .pdf report of at most six pages that answers the following questions:

a) What is lock-free programming and what novel risks does it create for program correctness?
b) How do we establish correctness of a non-blocking algorithm?

A strong report will combine support from primary and secondary sources with your own analysis. You are free to select your own sources, but there should be at least six distinct sources in your reference list.

## Evaluation

The report will be graded on a real-valued scale from 0.0 (no submission) to 4.0 (perfect score), with up to two points obtained for each of the questions above. The questions will be evaluated subjectively by the instructor as follows:


### Lock-free programming

A report that obtains full marks on this question, will, in the instructor's opinion, exhibit the following features:

- A competent, third-year Software Engineering student, after reading the report, would be able to describe the concurrency challenges that lock-free programming is meant to address
- A competent, third-year Software Engineering student, after reading the report, would be able to define non-blocking and lock-free programming formally and with an effective illustration
- A competent, fourth-year Software Engineering student, after reading the report and with reference to architecture and instruction sets, would understand how lock-free programming is possible as an alternative to mutual exclusion
- A competent, fourth-year Software Engineering student, after reading the report, would be able to describe a couple examples of common problems that arise uniquely in non-blocking algorithms

Each of these features will be evaluated on a discrete scale of {0/8, 1/4, 3/8, or 1/2}, depending on the clarity and precision of the description, as well as the quality of the sources chosen to support the exposition.


### Correctness

A report that obtains full marks on this question, will, in the instructor's opinion, exhibit the following features:

- A detailed example that exemplifies how a theoretical proof technique, such as linearisability, could demonstrate correctness of a non-blocking algorithm
- A visual representation of the concept of linearisability (perhaps inspired by Section 2.1 of [HS08])

Each of these features will be evaluated on a discrete scale of {0/4, 1/3, 2/3, or 1.0}, depending on the clarity and precision of the description.


## Due Date

The report is due at 23:59 AoE, Friday 21 October 2022; however, there is a grace period of one week during which a late assignment will still be considered to be on time.
