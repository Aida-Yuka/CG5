#include "Test.hlsli"

struct PixelShaderOutput
{
	float4 color : SV_TARGET0;
};

PixelShaderOutput main(VertexShaderOutput input)
{
	PixelShaderOutput output;
	float2 uv = input.texcoord;

	//位置セット(x y z w)か、カラーセット(r g b a)でアクセス出来る
	output.color = float4(uv.x, uv.y, 0.0f, 0.0f);

	return output;
}