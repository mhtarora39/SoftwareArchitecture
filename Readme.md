#### Component  

Small building block of Architecture

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
### Broker Topology
  



