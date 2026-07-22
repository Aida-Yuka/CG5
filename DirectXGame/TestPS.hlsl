struct PixelShaderOutput{
	float4 color : SV_TARGET0;
};

float4 main() : SV_TARGET
{
	PixelShaderOutput output;
	output.color = float4(1.0f, 1.0f, 1.0f, 1.0f);
	return output;
}