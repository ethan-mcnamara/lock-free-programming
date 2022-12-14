# SENG 490: Final Report

## Objective

This final report should present a software prototype for this project, with a particular emphasis on concurrency support. It focuses on the following course-level learning outcomes:

 3. Given a problem statement, design a provably correct multi-threaded software application that can leverage non-blocking algorithmic techniques, such as atomic fetches, CAS loops and load-link/store-conditionals.
 4. Given a multi-threaded application, design a set of experiments (or tests) to verify correctness of the implementation in a multi-threaded context.
 5. Given a series of advanced lectures aimed at graduate students and/or senior practitioners, synthesise the content in a manner that you can incorporate into your own Software Engineering practice for self-directed professional development.

In addition to describing the prototype design and implementation, the report should reflect on lessons learned from incorporating lock-free concurrency into a scheduling application. 


## Specifications

You should prepare a .pdf report of at most twelve pages that describes the prototype implementation. In particular, it should:

  * describe the software architecture implemented in the prototype
  * provide important details necessary to reproduce the prototype from the design description 
  * provide evidence of correctness for the design and the prototype
  * reflect on the process from design to prototype implementation with a focus on aspects of concurrency

A strong report will be tease out details that would not have been apparent at the beginning of the semester, even to somebody who had taken a course in concurrency such as UVic's Summer 2022 CSC 485C. It will likely reuse content from previous reports that has already been reviewed.

## Evaluation

The report will be graded on a real-valued scale from 0.0 (no submission) to 4.0 (perfect score), with up to one point obtained for each of the aspects above. The aspects will be evaluated subjectively by the instructor as follows:


### Software Architecture

Your report should assume that the reader is not familiar with the domain for this project (e.g., it is a new co-op student) and you want to provide enough context so that they can understand what the objectives of this system are. Moreover, the report should indicate what functionality the system should support and the constraints impacting that functionality. Compatability with some linearised history **must** be a requirement for the system. The requirements that you identified and how they were supported by the software architecture should be clear in the report.

A report that obtains full marks on this question, will, in the instructor's opinion, exhibit the following features:

 - The architecture, as described in the report, clearly meets the requirements that have been specified
 - The multi-threaded architecture is provably free from deadlocks, but also guarantees some degree of liveness

Each of these features will be evaluated on a discrete scale of {0/8, 1/4, 3/8, or 1/2}, depending on the clarity of the description. This section will probably have a high degree of reuse from prior reports.


### Prototype Implementation

Going from design to implementation can be messy. You should provide enough detail that somebody could plausibly develop a new prototype that is, in general terms, equivalent to the one that you have developed. A particular focus should be placed on _state_, how that is represented at a very detailed level, and how that is synchronised among threads. This section can focus on just those components that involve concurrency.

A report that obtains full marks on this question, will, in the instructor's opinion, exhibit the following features:

 - Specific data structures and the ownership of data is clear enough to be reproduced exactly, even down to the level of data alignment and cache coherency
 - How data structures are manipulated to match the data flow described in the design document is clear enough that one could reproduce it with reasonable enough faithfulness to not alter major conclusions about this project

Each of these features will be evaluated on a discrete scale of {0/8, 1/4, 3/8, or 1/2}, depending on the clarity of the description.


### Evidence of Correctness

Throughout this project, you have focused on theoretical correctness in the software design. A second layer of correctness is introduced when producing a prototype, namely its consistency with the design proven to be theoretically correct. Your report should address both these notions of correctness: that the design has both safety and liveness (probably reusing from prior reports); and that the prototype is consistent with the design (requiring software testing). The report should provide adequate evidence of both.

A report that obtains full marks on this question, will, in the instructor's opinion, exhibit the following features:

- It is easy to see which data are subject to concurrency challenges and how both safety and liveness are guaranteed by the algorithm
- Evidence provided in the report convinces the reader that the prototype implementation is correct in terms of both safety and liveness

Each of these features will be evaluated on a discrete scale of {0/8, 1/4, 3/8, or 1/2}, depending on the clarity of the description and the technical precision with which the challenges are identified.


### Reflections

Although the project has finished, personal development has not. It is worth reflecting at this point on:
  - what have you learned through this process that was different from what you took out of the CSC 485C concurrency course this summer?
  - based on this project, when would you use lock-free techniques in the future?
  - how important was prototype development to this project compared to having done another iteration of architecture design?
  - what would you do differently if you were to start this project again?

This component could be quite personal and is optional in the report itself. It will be evaluated on a ternary {0, 0.5, 1} scale based on whether it is clear, either from the report or from personal communications, that meaningful reflection has taken place. Particularly impactful reflection would influence the way the instructor teaches concurrency to future students.


## Due Date

The report is due at 23:59 AoE, Wednesday 21 December 2022; there is a grace period of **two days** during which a late assignment will still be considered to be on time. Draft submissions received by 17 December will receive preliminary feedback in advance of the deadline.
