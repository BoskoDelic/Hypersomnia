-- PHYSICS COLLISION LAYERS --
filters = {
	STATIC_OBJECT = "ALL",

	CHARACTER = {
		"STATIC_OBJECT", "REMOTE_CHARACTER"
	},
	
	REMOTE_CHARACTER = {
		"STATIC_OBJECT", "BULLET", "CHARACTER", "REMOTE_CHARACTER"
	},
	
	BULLET = {
		"STATIC_OBJECT", "REMOTE_CHARACTER"
	},
	
	REMOTE_BULLET = {
		"STATIC_OBJECT"
	}
}

-- processing

local all_keys = {}
local all_categories = {}

for k, v in pairs(filters) do
	table.insert(all_keys, k)
end

create_options(all_keys, all_categories)

for k, v in pairs(filters) do
	if type(v) == "string" and v == "ALL" then
		filters[k] = all_keys
	end
end

for k, v in pairs(filters) do
	local mask = 0
	
	for i=1, #filters[k] do
		mask = bitor(all_categories[filters[k][i]], mask)
	end
	
	filters[k] = create(b2Filter, {
		categoryBits = all_categories[k],
		maskBits = mask
	})
end
