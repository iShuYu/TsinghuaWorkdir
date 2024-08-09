rm -rf Tuple.root
rm -rf Tuple_prompt.root
rm -rf Tuple_fromb.root
hadd Tuple_fromb.root Tuple_fromb_MagUp.root Tuple_fromb_MagDown.root
hadd Tuple_prompt.root Tuple_prompt_MagUp.root Tuple_prompt_MagDown.root
hadd Tuple.root Tuple_MagUp.root Tuple_MagDown.root
