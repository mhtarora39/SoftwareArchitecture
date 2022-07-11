#### Component  

Small building block of Architecture

### Topics:

* What Is Domain-Driven Design (DDD)
* Building Domain Knowledge
* The Ubiquitous Language
* The Need for a Common Language
* Creating the Ubiquitous Language
* The Building Blocks Of A Model-Driven Design
* Layered Architecture
* Entities
* Value Objects
* Services
* Modules
* Aggregates
* Factories
* Repositories
* Refactoring Toward Deeper Insight
* Continuous Refactoring
* Bring Key Concepts Into Light
* Preserving Model Integrity
* Bounded Context
* Continuous Integration
* Context Map
* Shared Kernel
* Customer-Supplier
* Conformist
* Anticorruption Layer
* Separate Ways
* Open Host Service
* Distillation

## Types Of Architecture 

1.**Layer Architecture**

<img src="./Layerd%20Architecture.jpg" width="50%" style="vertical-align:middle;margin:50px 5%">


* Build out of layer ( i.e Tcp IP)<br>
  a. **Layer is closed (issue)** ( We can't send or access layer directly ).</br>
  b. Layer of isolation (Each layer is component and binded each other by interface).    
  c. No effect on any other layer if any underlying layer change.<br>
  d. Separation of concerns. <br>
  e. Architect decide which layer needs to open.<br>
  f. Open layer introduce cross layer concerns

### Layer Architecture Concerns

* Good General Architecture. 
* Sink Hole : Which out for architecture sinkhole anti-pattern (open layers).
* 80% close and 20% open layers.If you are doing only pass through then look for good architecture
* Tends to land at monolithic.

### Analysis 

  1. Overall Agility ( Low ) : Overall design : Small Design / Interface change leads to change everything
  2. Deployment ( Low )     : Small Change required redeployment.
  3. Testability ( Good )   : Easy to test each layer.
  4. Performance ( Low )    : Performance is low as multiple passes.
  5. Scalability ( Low )    : Layers are rigid
  6. Development ( Good )   : Easy to develop.
  7. Complexity  ( Good )   : Easy to develop.
  8. Loose Coupling ( Low ) : Tightly coupled with layer.


2.**Event Driven Architecture**

### Mediator Topology
All events are orchestrated by the Event Mediator. Events are published to mediator . This is a application or program which will decide 
* what subscriber gets the which event.
* Mediator sometime stores the states , data for complex application.

<img src="./event-mediator.png" width="50%" style="vertical-align:middle;margin:50px 5%"/>

### Broker Topology
All the events are send to bus (a queue).
* It just stores the events as it is.
* events can be retrieves in FIFO manner.

<img src="./event-bus.jpeg" width="50%" style="vertical-align:middle;margin:50px 5%"/>



  



