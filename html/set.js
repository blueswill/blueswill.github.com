function Set()
{
   this.values={};
   this.n=0;
   Set.prototype.add.apply(this,arguments);
}

Set.prototype.add=function()
{
   for(var i=0;i<arguments.length;i++)
   {
      var args=arguments[i];
      var str=Set._v2s(args);
      if(!this.values.hasOwnProperty(str))
      {
	 this.values[str]=args;
	 this.n++;
      }
   }
   return this;
}

Set.prototype.remove=function()
{
   for(var i=0;i<arguments.length;i++)
   {
      var args=arguments[i];
      var str=Set._v2s(args);
      if(this.values.hasOwnProperty(str))
      {
	 delete this.values[str];
	 this.n--;
      }
   }
   return this;
}

Set.prototype.contains=function(value)
{
   return this.values.hasOwnProperty(Set._v2s(value));
}

Set.prototype.size=function()
{
   return this.n;
}

Set.prototype.foreach=function(f,context)
{
   for(var str in this.values)
   {
      f.call(context,this.values[str]);
   }
   return this;
}

Set._v2s=function(value)
{
   switch(value)
   {
      case 'null':return 'n';
      case 'undefined':return 'u';
      case true:return 't';
      case false:return 'f';
      default:switch(typeof value)
	      {
		 case 'number':return '#'+value;
		 case 'string':return '"'+value;
		 default:return '@'+objectId(value);
	      }
   }

   function objectId(value)
   {
      var prop="|**objectid**|";
      if(!values.hasOwnProperty(prop))
	 o[prop]=Set._v2s.next++;
      return o[prop];
   }
}

Set._v2s.next=100;
