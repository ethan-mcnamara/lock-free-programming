# SENG 490: Design Report

## Objective

This interim report should describe the software architecture for this project, with a particular emphasis on concurrency support. It focuses on the following course-level learning outcomes:

 2. Given a concurrent application, prove theoretical correctness using the concept of linearisability [HW90].
 3. Given a problem statement, design a provably correct multi-threaded software application that can leverage non-blocking algorithmic techniques, such as atomic fetches, CAS loops and load-link/store-conditionals.
 4. Given a multi-threaded application, design a set of experiments (or tests) to verify correctness of the implementation in a multi-threaded context.


## Specifications

You should prepare a .pdf report of at most six pages that describes the proposed software architecture at several layers of abstraction. In particular, it should include:

  * the context and system requirements, including the test/experiment harness
  * a high-level, conceptual view of the entire system, its components, and how they interact
  * a logical description of shared data and approaches to managing synchronisation
  * an algorithmic description of one instance in the system of lock-free synchronisation, with evidence for both liveness and safety

A strong report will isolate layers of abstraction effectively, while still maintaining compatability where the layers meet. For example, the need for the lock-free algorithm should be well motivated at each abstraction layer above.

## Evaluation

The report will be graded on a real-valued scale from 0.0 (no submission) to 4.0 (perfect score), with up to one point obtained for each of the aspects above. The aspects will be evaluated subjectively by the instructor as follows:


### Context and Requirements

Your report should assume that the reader is not familiar with the domain for this project (e.g., it is a new co-op student) and you want to provide enough context so that they can understand what the objectives of this system are. Moreover, the report should indicate what functionality the system should support and the constraints impacting that functionality. Observe that one functional requirement is that you need to assess the performance of your lock-free module, which is presumed to be a hotspot for the entire system.

A report that obtains full marks on this question, will, in the instructor's opinion, exhibit the following features:

 - Sufficient context is provided to understand why a dispatch system is needed, why it needs multi-threading support, and why it is important to evaluate performance
 - The requirements are plausibly derived from the context and compellingly justify the use of lock-free techniques

Each of these features will be evaluated on a discrete scale of {0/8, 1/4, 3/8, or 1/2}, depending on the clarity of the description.


### Conceptual Design

A high-level overview of the system should describe how different components interact to support the requirements. The system architecture should ideally be extensible and effectively modularised; it should also support all requirements identified above with no duplication of functionality. Finally, it should focus only on *what* system components exist and *what* information the components share, not *how* they behave nor *how* they coordinate resources.

A report that obtains full marks on this question, will, in the instructor's opinion, exhibit the following features:

 - It is easy to see how the system will cover all requirements with minimal complexity and no redundancy
 - It is easy to understand from the report how the system is composed and how information flows from an initial state to a final state

Each of these features will be evaluated on a discrete scale of {0/8, 1/4, 3/8, or 1/2}, depending on the clarity of the description.


### Data Management

The primary challenge with concurrency is the management of shared resources, in particular data assets. The report should describe the data assets (which could be in repositories and/or in class member variables), what causes those assets to mutate, and how concurrent mutations are managed. This description should be at a logical level, e.g., what techniques are deployed, not at an algorithmic/implementation level.

A report that obtains full marks on this question, will, in the instructor's opinion, exhibit the following features:

- It is easy to see which data are subject to concurrency challenges and what causes that concurrency, as well as which data are irrelevant to any proofs of safety and liveness
- It is easy to convince oneself that if each concurrency mechanism is implemented correctly, that the entire system will compose into one that guarantees system-wide safety and liveness

Each of these features will be evaluated on a discrete scale of {0/8, 1/4, 3/8, or 1/2}, depending on the clarity of the description and the technical precision with which the challenges are identified.


### Lock-free Concurrency

You should provide a detailed algorithmic description of one module, which must utilise lock-free techniques to manage shared, mutable data assets. The algorithm should be accompanied by a mathematical proof of both liveness and safety.  

A report that obtains full marks on this question, will, in the instructor's opinion, exhibit the following features:

- The algorithm appears to meet the definition of "lock-free" and to alway sproduce the correct solution
- The proof convincingly argues for both safety and liveness (e.g., by adequately justifying a point of linearisation)

Each of these features will be evaluated on a discrete scale of {0/8, 1/4, 3/8, or 1/2}, depending on technical accuracy.


## Due Date

The report is due at 23:59 AoE, Monday 21 November 2022; however, there is a grace period of one week during which a late assignment will still be considered to be on time. Draft submissions received by 14 November will receive preliminary feedback in advance of the deadline.
