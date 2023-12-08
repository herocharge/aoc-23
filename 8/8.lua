instructions = io.read()
mt = io.read()
ht = {}
while true do 
	local inp = io.read()
	if inp == "" then
		break
	end

	result = {}
	i = 0
	
	for val in string.gmatch(inp, "[A-Z][A-Z][A-Z]") do
		result[i] = val
		i = i + 1
	end

	ht[result[0]] = {["L"]=result[1], ["R"]=result[2]}
end

steps = 1
idx = 1
curr = "AAA"
while true do
	if idx == string.len(instructions) + 1 then
		idx = 1
	end
	chr = string.sub(instructions, idx, idx)
	print("curr=",curr," idx= ", idx)
	curr = ht[curr][chr]
	if curr == "ZZZ" then
		break
	end
	idx = idx + 1
	steps = steps + 1
end

print(steps)
