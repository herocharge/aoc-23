instructions = io.read()
mt = io.read()
starts = {}
sidx = 1
ends = {}
ht = {}
while true do 
	local inp = io.read()
	if inp == "" then
		break
	end

	result = {}
	i = 0
	
	for val in string.gmatch(inp, "[A-Z0-9][A-Z0-9][A-Z0-9]") do
		result[i] = val
		i = i + 1
	end
	print(result[0], result[1], result[2])

	if string.sub(result[0], 3, 3) == "A" then
		starts[sidx] = result[0]
		sidx = sidx + 1
	end
	if string.sub(result[0], 3, 3) == "Z" then
		ends[result[0]] = true
	end
	if string.sub(result[1], 3, 3) == "Z" then
		ends[result[1]] = true
	end
	if string.sub(result[2], 3, 3) == "Z" then
		ends[result[2]] = true
	end

	ht[result[0]] = {["L"]=result[1], ["R"]=result[2]}
end

steps = 1
idx = 1

while true do
	if idx == string.len(instructions) + 1 then
		idx = 1
	end
	chr = string.sub(instructions, idx, idx)
	local done = 0
	for tidx, curr in ipairs(starts) do
		local kk = ht[curr][chr]
		starts[tidx] = kk
		if ends[kk] then
			done = done + 1	
		end
	end
	if done == sidx-1 then
		break
	end
	idx = idx + 1
	steps = steps + 1
	if steps%100000 == 0 then
		print(steps)
	end
end

print(steps)
