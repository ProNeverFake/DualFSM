
// static const char *left_arm_tree = R"(
//        <root BTCPP_format="4" >
//             <BehaviorTree ID="left_arm">
//                 <Sequence name="root_sequence">
//                     <ReactiveSequence>
//                         <ReactiveFallback>
//                             <Condition />
//                             <Action ID="plugin="ToolLoaded" />
//                         <ReactiveFallback/>
//                         <Action ID= "PourWater">
//                     </ReactiveSequence>

//                     <ReactiveSequence>
//                         <ReactiveFallback>
//                             <Condition ID="Nothing"  />
//                             <Action ID="plugin="ToolLoaded" />
//                         <ReactiveFallback/>
//                         <Action ID= "PourWater">
//                     </ReactiveSequence>
//                 </Sequence>
//             </BehaviorTree>
//         </root>
//         )";



// static const char *right_arm_tree = R"(
//         <root BTCPP_format="4" >
//             <BehaviorTree ID="right_arm">
//                 <Sequence name="root_sequence">
//                     <ReactiveSequence>
//                         <ReactiveFallback>
//                             <Condition ID="CupInHand" />
//                             <Action ID="plugin="ToolLoaded" />
//                         <ReactiveFallback/>
//                         <Action ID= "PourWater">
//                     </ReactiveSequence>

//                     <ReactiveSequence>
//                         <ReactiveFallback>
//                             <Condition ID="Nothing"  />
//                             <Action/>
//                         <ReactiveFallback/>
//                         <Action ID= "PourWater">
//                     </ReactiveSequence>
//                 </Sequence>
//             </BehaviorTree>
//         </root>
//         )";


// static const char *tree_map = R"(
//        <root BTCPP_format="4" >
//             <BehaviorTree ID="dual_arm">
//                 <ParallelAllNode name="root_parallel">
//                     <SubTree ID="left_arm" />
//                     <SubTree ID="right_arm" />
//                 </ParallelAllNode>
//             </BehaviorTree>


//             <BehaviorTree ID="left_arm">
//                 <Sequence name="root_sequence">
//                     <ReactiveSequence>
//                         <ReactiveFallback>
//                             <Condition name=""/>
//                             <Action ID="plugin="ToolLoaded" />
//                         <ReactiveFallback/>
//                         <Action ID= "PourWater">
//                     </ReactiveSequence>

//                     <ReactiveSequence>
//                         <ReactiveFallback>
//                             <Condition ID="Nothing"  />
//                             <Action ID="plugin="ToolLoaded" />
//                         <ReactiveFallback/>
//                         <Action ID= "PourWater">
//                     </ReactiveSequence>
//                 </Sequence>
//             </BehaviorTree>

//             <BehaviorTree ID="right_arm">
//                 <Sequence name="root_sequence">
//                     <ReactiveSequence>
//                         <ReactiveFallback>
//                             <Condition ID="CupInHand" />
//                             <Action ID="plugin="ToolLoaded" />
//                         <ReactiveFallback/>
//                         <Action ID= "PourWater">
//                     </ReactiveSequence>

//                     <ReactiveSequence>
//                         <ReactiveFallback>
//                             <Condition ID="Nothing"  />
//                             <Action/>
//                         <ReactiveFallback/>
//                         <Action ID= "PourWater">
//                     </ReactiveSequence>
//                 </Sequence>
//             </BehaviorTree>
//         </root>
//         )";

                    

static const char *tree_map = R"(
       <root BTCPP_format="4" >
            <BehaviorTree ID="dual_arm"> 
                <SequenceWithMemory name="root_sequence">
                    <Script code="@water_poured:=false" />
                    <Script code="@cup_in_place:=false" />
                    <Script code="@do_not_wait:=true" />
                    <ParallelAll name="root_parallel">
                        <SubTree ID="left_arm" />
                        <SubTree ID="right_arm" />
                    </ParallelAll>
                </SequenceWithMemory>
            </BehaviorTree>


            <BehaviorTree ID="left_arm">
                <Sequence name="root_sequence">
                    <ReactiveSequence>
                        <Wait name="nothing" _skipIf="@do_not_wait==true"/>
                        <MoveNode name="fetch_cup" _onSuccess="@cup_in_place:=true"/>
                    </ReactiveSequence>

                    <ReactiveSequence>
                        <Wait name="water poured" _skipIf="@water_poured==true"/>
                        <MoveNode name="put_cup"/>
                    </ReactiveSequence>
                </Sequence>
            </BehaviorTree>

            <BehaviorTree ID="right_arm">
                <Sequence name="root_sequence">
                    <ReactiveSequence>
                        <Wait name="nothing" _skipIf="@do_not_wait==true"/>
                        <MoveNode name="get_kettel"/>
                    </ReactiveSequence>

                    <ReactiveSequence>
                        <Wait name="cup_in_place" _skipIf="@cup_in_place==true"/>
                        <MoveNode name="pour_water"  _onSuccess="@water_poured:=true"/>
                    </ReactiveSequence>
                </Sequence>
            </BehaviorTree>
        </root>
        )";